fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun printInts(list: List<Int>) {
    list.forEach() {
        print("$it ")
    }
    println()
}

fun main() {
    val a = readInts()
    var n = a[0]
    val k = a[1]
    if (n < k) {
        println("NO")
        return
    }
    var x = 1
    repeat(30) {
        x *= 2
    }
    val cnt = MutableList (31) { 0 }
    repeat(31) {
        if (n >= x) {
            n -= x
            cnt[it]++
        }
        x /= 2
    }
    var tm = k - cnt.sum()
    if (tm < 0) {
        println("NO")
        return
    }
    repeat(31) {
        while (it + 1 < 31 && tm > 0 && cnt[it] > 0) {
            tm--
            cnt[it + 1] += 2
            cnt[it] -= 1
        }
    }
    val ans = mutableListOf<Int>()
    x = 1
    repeat(30) {
        x *= 2
    }
    repeat(31) {
        while (cnt[it] > 0) {
            cnt[it]--
            ans.add(x)
        }
        x /= 2
    }
    println("YES")
    printInts(ans)
}