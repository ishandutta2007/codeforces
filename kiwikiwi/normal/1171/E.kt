fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }

fun main(args: Array<String>) {
    var n = nextInt()
    var s = nextLn().toSet()
    println(if (s.size < n || n == 1) "YES" else "NO")
}