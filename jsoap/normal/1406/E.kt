import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val isPrime = BooleanArray(n + 1) { true }
    val primePowers = mutableListOf<Int>()
    for (p in 2..n) {
        if (isPrime[p]) {
            var pow = p.toLong()
            while (pow <= n.toLong()) {
                primePowers.add(pow.toInt())
                pow *= p.toLong()
            }
            for (k in 2 * p..n step p) {
                isPrime[k] = false
            }
        }
    }
    val rem = BooleanArray(n + 1) { true }
    var answer = 1
    var foundFirst = false
    var totalRem = n
    for (j in 0..(primePowers.size + 99) / 100) {
        for (j2 in j * 100 until min(primePowers.size, (j + 1) * 100)) {
            val p = primePowers[j2]
            var prev = 0
            for (k in p..n step p) {
                if (rem[k]) {
                    prev++
                    rem[k] = false
                    totalRem--
                }
            }
            //println("p = $p, prev = $prev")
            println("B $p")
            val actual = readLine()!!.toInt()
            if (actual != prev) {
                //println("lcm with $p")
                answer = lcm(answer, p)
            }
        }
        if (!foundFirst) {
            println("A 1")
            val actual = readLine()!!.toInt()
            if (actual != totalRem) {
                foundFirst = true
                for (j2 in j * 100 until min(primePowers.size, (j + 1) * 100)) {
                    val p = primePowers[j2]
                    println("A $p")
                    val bit = readLine()!!.toInt()
                    if (bit == 1) {
                        //println("lcm with $p")
                        answer = lcm(answer, p)
                    }
                }
            }
        }
    }
    println("C $answer")
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
fun lcm(a: Int, b: Int): Int = a * (b / gcd(a, b))