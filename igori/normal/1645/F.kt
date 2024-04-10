fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun printInts(list: List<Int>) {
    list.forEach() {
        print("$it ")
    }
    println()
}

fun main() {
    val n = readInt()
    val a = readInts()
    val lim = 150005
    val cnt = MutableList(lim) { 0 }
    a.forEach {
        cnt[it - 1]++
    }
    repeat(lim - 2) {
        if (cnt[it] == 0 && cnt[it + 1] > 0) {
            cnt[it]++
            cnt[it + 1]--
        }
        if (cnt[it] > 1) {
            cnt[it]--
            cnt[it + 1]++
        }
    }
    val ans = cnt.count { it > 0 }
    println(ans)
}