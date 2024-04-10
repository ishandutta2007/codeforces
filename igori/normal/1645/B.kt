fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }

fun main() {
    val n = readInt()
    val s = readLine()!!
    var j = 0
    val ans = StringBuilder()
    for (i in 0 until n) {
        j += i
        if (j >= n)
            break
        ans.append(s[j])
    }
    println(ans)
}