fun nextInt() = readLine()!!.toInt()
fun nextInts() = readLine()!!.split(" ").map { it.toInt() }

fun main(args: Array<String>) {
    var (a, b, c) = nextInts()
    println(3 * minOf(a, b - 1, c - 2) + 3)
}