import kotlin.math.min
import kotlin.math.max

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }

fun solve() {
    var ans = 0
    val words = mutableListOf<List<String>>()
    while (true) {
        val s = readLine()
        if (s == null)
            break
        val w = s!!.split("[^a-z]".toRegex())
        words.add(w)
        ans += s!!.count { !it.isLetter() } + 1
    }
    val trie = mutableListOf<MutableList<Int>>()
    val cnt = mutableListOf<Int>()
    val term = mutableListOf<Int>()
    trie.add(MutableList(26) { 0 })
    cnt.add(0)
    term.add(0)

    fun put(s: String) {
        var pnt = 0
        cnt[pnt] += 1
        s.forEach {
            val id = it - 'a'
            pnt = trie[pnt][id]
            cnt[pnt]++
        }
        term[pnt]++
    }

    words.flatten().forEach{ s ->
        var pnt = 0
        var cnt1 = 0
        var ends = 0
        s.forEach {
            val id = it - 'a'
            if (trie[pnt][id] == 0) {
                trie[pnt][id] = trie.size
                trie.add(MutableList(26) { 0 })
                cnt.add(0)
                term.add(0)
            }
            pnt = trie[pnt][id]
            if (cnt[pnt] == 1)
                cnt1++
            if (term[pnt] == 1 && cnt[pnt] == 1)
                ends++
        }
        if (cnt1 == 0 || ends == 0 || (cnt[pnt] == 1 && term[pnt] == 0))
            ans += s.length
        else {
            ans += min(s.length - cnt1 + 2, s.length)
            //println("$s, $cnt1 -> ${min(s.length - cnt1 + 2, s.length)}")
        }
        if (term[pnt] == 0)
            put(s)
    }
    println(ans)
}

fun main()
{
    val t = 1
    repeat(t) {
        solve()
    }
}