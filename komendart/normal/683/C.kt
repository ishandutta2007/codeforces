fun main(args: Array<String>) {
    val x = readLine()!!.split(' ').map(String::toInt)
    val y = readLine()!!.split(' ').map(String::toInt)
    val a = arrayListOf<Int>()
    val b = arrayListOf<Int>()
    for (i in 1..x[0]) a.add(x[i])
    for (i in 1..y[0]) b.add(y[i])
    var cnt = 0
    for (i in a) {
        if (i !in b) cnt++
    }
    for (i in b) {
        if (i !in a) cnt++
    }
    print(cnt)
    for (i in a) {
        if (i !in b) {
            print(" ")
            print(i)
        }
    }
    for (i in b) {
        if (i !in a) {
            print(" ")
            print(i)
        }
    }
}