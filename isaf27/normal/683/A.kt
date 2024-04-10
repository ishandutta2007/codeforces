fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if (0 <= x && x <= a && 0 <= y && y <= a)
    {
         if (0 < x && x < a && 0 < y && y < a)
            println(0)
        else
            println(1)
    }
    else
        println(2)
}