fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }

fun main(args: Array<String>) {
    var n = nextInt()
    var a = nextLn()
    var b = ArrayList<Char>()
    for (c in a) {
        if (b.size % 2 == 0) {
            b.add(c)
        } else if (c != b.last()) {
            b.add(c)
        }
    }
    if (b.size % 2 != 0) {
        b.removeAt(b.size - 1)
    }
    println(n - b.size)
    println(b.joinToString(""))
}