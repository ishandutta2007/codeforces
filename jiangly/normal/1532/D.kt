import kotlin.collections.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(' ').map(String::toInt)
fun readLong() = readLn().toInt()
fun readLongs() = readLn().split(' ').map(String::toLong)

fun main() {
    var n = readInt()
    var a = readInts().sorted()
    var ans = 0
    for (i in 0 until n step 2) {
        ans += a[i + 1] - a[i]
    }
    println(ans)
}