fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(' ').map(String::toInt)
fun readLong() = readLn().toInt()
fun readLongs() = readLn().split(' ').map(String::toLong)

fun main() {
    var t = readInt()
    repeat(t) {
        var (a, b, k) = readLongs()
        println((k + 1) / 2 * a - k / 2 * b)
    }
}