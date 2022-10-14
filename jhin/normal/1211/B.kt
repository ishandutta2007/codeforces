import java.util.ArrayList


fun main()
{

    var b=readLine()!!.toInt()
    var array=readLine()!!.split(' ').map(String::toLong)

var myarray=ArrayList<Long>()
var mx:Long=0;var indx=0;
    for(i in 0..array.size-1)
    {
        myarray.add(array[i])
        if(myarray[i]>=mx){mx=myarray[i];indx=i}
    }
print((mx-1)*b+indx+1)

}