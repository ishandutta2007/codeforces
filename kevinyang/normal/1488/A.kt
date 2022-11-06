fun main(args: Array<String>) {
    var t = readLine()!!.toInt();
    repeat(t){
    	var (x,y) = readLine()!!.split(" ").map{it.toInt()};
    	var pows = listOf(1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000);
    	var ans = 0
    	while(y>0){
    		if(y<x){
    			ans+=y;
    			break;
    		}
    		for(i in 9 downTo 0){
	    		var pow = pows[i];
	    		if(y/x>=pow){
	    			y-=pow*x;
	    			ans++;
	    			break;
	    		}
	    	}
    	}
    	println(ans);
    }
}