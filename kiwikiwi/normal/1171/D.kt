fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }

fun main(args: Array<String>) {
    var (x, y, z) = nextInts()
    var (a, b, c) = nextInts()
    println(if (a >= x && a - x + b >= y && a + b - x - y + c >= z) "YES" else "NO")
}