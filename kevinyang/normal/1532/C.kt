fun main(args: Array<String>) {
    var t = readLine()!!.toInt();
    repeat(t){
        var (n,k) = readLine()!!.split(" ").map{it.toInt()};
        var cur = 0
        for(i in 1..n){
            print((cur+97).toChar());
            cur++;
            cur%=k;
        }
        println();
    }
}