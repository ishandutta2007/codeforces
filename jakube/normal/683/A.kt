
fun main(args: Array<String>) {
    val l: MutableList<Int> = mutableListOf()
    for (s in (readLine() as String).split(' ')) {
        l.add(s.toInt())
    }


    val a = l[0]
    val x = l[1]
    val y = l[2]

    if (x > 0 && x < a && y > 0 && y < a)
        println(0)
    else if ((x == 0 || x == a) && y >= 0 && y <= a)
        println(1)
    else if ((y == 0 || y == a) && x >= 0 && x <= a)
        println(1)
    else
        println(2)
}