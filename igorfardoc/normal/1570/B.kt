fun main() {
    var a1 = readInt();
    var a2 = readInt();
    var k1 = readInt();
    var k2 = readInt();
    var n = readInt();
    print(maxOf(n - (k1 - 1) * a1 - (k2 - 1) * a2, 0));
    print(" ");
    if(k2 < k1) {
        var temp = k1;
        k1 = k2;
        k2 = temp;
        temp = a1;
        a1 = a2;
        a2 = temp;
    }
    var can = minOf(a1, (n - n % k1) / k1);
    var res = 0;
    res += can;
    n -= can * k1;
    res += minOf(a2, (n - n % k2) / k2);
    println(res);
}

private fun readInt() = readLine()!!.toInt();
private fun readInts() = readLine()!!.split(" ").map{x -> x.toInt()};