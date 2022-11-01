fun main() {
    repeat(readLine()!!.toInt()) {
        var n = readLine()!!.toInt()
        if (n % 2 == 1) {
            println("Bob")
        } else {
            var lg = 0
            while (n % 2 == 0) {
                n /= 2
                lg++
            }
            println(if (n != 1 || lg % 2 == 0) "Alice" else "Bob")
        }
    }
}