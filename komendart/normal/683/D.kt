fun main(args: Array<String>) {
    val (q) = readLine()!!.split(' ').map(String::toInt)
    for (i in 1..q) {
        val (n, m, p) = readLine()!!.split(' ').map(String::toInt)
        var flag = false
        for (i in 1..n) {
            if (p % i == 0 && p / i <= m) {
                flag = true
            }
        }
        if (flag) println("Yes")
        else println("No")
    }
}