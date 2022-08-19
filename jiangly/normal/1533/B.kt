import kotlin.collections.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(' ').map(String::toInt)
fun readLong() = readLn().toInt()
fun readLongs() = readLn().split(' ').map(String::toLong)

fun main() {
    var t = readInt()
    repeat(t) {
        var n = readInt()
        var ans = false
        var x = readInts()
        for (i in 1..n - 1) {
            if ((x[i] - x[i - 1]) % 2 == 0) {
                ans = true
            }
        }
        println(if (ans) "YES" else "NO")
    }
}