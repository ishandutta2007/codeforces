fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val s = readLine()!!
    if (s.all { it == s.first() } || s.first { it != s.first() } > s.first()) {
        println(s.first().toString().repeat(k))
    } else {
        var j = s.indexOfFirst { it < s.first() }
        while (true) {
            while (j < n && s[j] < s.first()) {
                j++
            }
            if (j == n || s[j] > s.first()) {
                break
            } else {
                var x = j
                while (x < n && s[x] == s[x % j]) {
                    x++
                }
                if (x == n || s[x] > s[x % j]) {
                    break
                } else {
                    j = x
                }
            }
        }
        val t = s.substring(0, j)
        val builder = StringBuilder()
        while (builder.length < k) {
            builder.append(t)
        }
        println(builder.substring(0, k))
    }
}