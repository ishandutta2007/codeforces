import kotlin.collections.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(' ').map(String::toInt)
fun readLong() = readLn().toInt()
fun readLongs() = readLn().split(' ').map(String::toLong)

fun main() {
    var t = readInt()
    repeat(t) {
        var (n, k) = readInts()
        var ans = 0
        var s = readLn()
        var a = ArrayList<Char>()
        for (x in s) {
            a.add(x)
        }
        var cnt = a.count({it == '1'})
        var cur = 0
        while (cnt > 0) {
            ans++
            if (a[cur] == '1') {
                cnt--
            }
            a.removeAt(cur)
            if (!a.isEmpty()) {
                cur = (cur + k - 1) % a.size
            }
        }
        println(ans)
    }
}