fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }
fun nextLongs() = nextStrings().map { it.toLong() }

var mod = 998244353

fun main(args: Array<String>) {
    var n = nextInt()
    var a = nextLongs().toMutableList()
    var b = nextLongs()
    for (i in 0 .. n - 1) {
        a[i] = a[i] * (i + 1) * (n - i)
    }
    a.sort()
    b = b.sorted()
    var ans : Long = 0
    for (i in 0 .. n - 1) {
        ans = (ans + (a[i] % mod) * b[n - 1 - i]) % mod
    }
    println(ans)
}