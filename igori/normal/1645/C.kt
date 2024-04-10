fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }

fun main() {
    val n = readInt()
    val a = readInts().sorted()
    var ans = 0
    a.forEachIndexed { index, it ->
        if (index % 2 == 0)
            ans -= a[index]
        else
            ans += a[index]
    }
    println(ans)
}