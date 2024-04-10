fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if (x in 1..a-1 && y in 1..a-1) {
        println(0)
    } else if (x !in 0..a || y !in 0..a) {
        println(2)
    } else {
        println(1)
    }
}