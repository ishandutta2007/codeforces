import java.util.ArrayList


fun main()
{

    var b=readLine()!!.toInt()
    var array=readLine()!!.split(' ').map(String::toInt)

var myarray=HashMap<Int,Int>()

    for(i in 0..array.size-1)
    {
        myarray[array[i]]=i+1
    }
    if(myarray.size<3)print("-1 -1 -1")
    else
    {var tst=myarray.toSortedMap()
        var tmp=0;for(i in tst.keys){print(""+tst[i]+" ");tmp++;if(tmp==3)break }}

}