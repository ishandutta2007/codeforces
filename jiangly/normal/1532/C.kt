fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(' ').map(String::toInt)
fun readLong() = readLn().toInt()
fun readLongs() = readLn().split(' ').map(String::toLong)

fun main() {
    var t = readInt()
    repeat(t) {
        var (n, k) = readInts()
        var s = CharArray(n)
        for (i in 0 until n) {
            s[i] = ('a'.toInt() + i % k).toChar()
        }
        println(s.joinToString(""));
    }
}