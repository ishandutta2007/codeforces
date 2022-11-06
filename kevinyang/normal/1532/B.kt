fun main(args: Array<String>) {
    var t = readLine()!!.toInt();
    repeat(t){
        var (a,b,k) = readLine()!!.split(" ").map{it.toLong()};
        if(k%2==1L){
            println((a-b)*(k/2)+a);
        }
        else{
            println((a-b)*k/2);
        }
    }
}