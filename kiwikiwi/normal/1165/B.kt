fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }

fun main(args: Array<String>) {
    var n = nextInt()
    var a = nextInts()
    a = a.sorted()
    var day = 0
    for (x in a) {
        if (x > day) {
            day += 1
        }
    }
    println(day)
}