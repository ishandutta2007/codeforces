import java.util.ArrayList


fun main()
{

    var (b,a)=readLine()!!.split(' ').map(String::toInt)
    var array=readLine()!!.split(' ').map(String::toInt)
    var myarray=ArrayList<Int> ()

    for(i in 0..array.size-1)
    {
        myarray.add(array[i])
    }
    myarray.sort()
    if(a==0)
    {
        if(myarray[0]==1)print(-1)
        else print(1)
        return
    }
    if(a==b)print(myarray[a-1])
    else {
        if (myarray[a-1]==myarray[a])print(-1)
        else print(myarray[a-1])
    }
}