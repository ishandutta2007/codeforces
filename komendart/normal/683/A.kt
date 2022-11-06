fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if (0 <= x && x <= a && 0 <= y && y <= a) {
        if (x == 0 || y == 0 || x == a || y == a) println(1)
        else println(0)
    }
    else println(2)
}