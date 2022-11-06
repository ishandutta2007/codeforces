fun main(args: Array<String>) {
    val T=readLine()!!.toInt();
    repeat(T){
        val (x, y) = readLine()!!.split(" ").map{it.toInt()};
        println(x+y);
    }
}