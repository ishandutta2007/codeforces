import java.lang.StringBuilder

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun printInts(list: List<Int>) {
    list.forEach() {
        print("$it ")
    }
    println()
}

@kotlin.ExperimentalStdlibApi
fun main() {
    val n = readInt()
    val s = readLine()!!
    val t = readLine()!!
    val a = MutableList(n) { s[it].code - 'a'.code }
    val b = MutableList(n) { t[it].code - 'a'.code }
    var memo = 0
    for (i in n - 1 downTo 0) {
        a[i] = a[i] + b[i] + memo
        if (a[i] >= 26) {
            a[i] -= 26
            memo = 1
        } else {
            memo = 0
        }
    }
    for (i in 0 until n) {
        val x = a[i] + memo * 26
        if (x % 2 == 0) {
            a[i] = x / 2
            memo = 0
        } else {
            a[i] = x / 2
            memo = 1
        }
    }
    val ans = StringBuilder()
    for (i in 0 until n) {
        ans.append((a[i] + 'a'.code).toChar())
    }
    println(ans)
}