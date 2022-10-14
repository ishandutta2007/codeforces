import java.util.ArrayList


fun main()
{

    var b=readLine()!!.toInt()
    var array=readLine()!!.split(' ').map(String::toLong)
    var myarray=ArrayList<Long> ()

    for(i in 0..array.size-1)
    {
        myarray.add(array[i])
    }
    myarray.sort()
    var mp=HashMap<Long,Boolean>()
    var st=myarray[0];
    for(i in 0..b-1)mp[myarray[i]]=true
    var newarray=ArrayList<Long>()
    newarray.add(st);mp[st]=false
    while(true)
    {
        var chk=false
        if(st%2==0.toLong()&&mp[st/2]!=null){
            if(mp[st/2]!!){
                st/=2
                mp[st]=false
                newarray.add(st)
                chk=true}
        }
        if(mp[st*3]!=null)
        {
            if(mp[st*3]!!){
                st*=3
                mp[st]=false
                newarray.add(st)
                chk=true}
        }
        if(!chk)break
    }
    st=newarray[0]
    newarray.reverse()
    while(true)
    {
        var chk=false;
        if(mp[st*2]!=null){
            if(mp[st*2]!!){
            st*=2
            mp[st]=false
            newarray.add(st)
            chk=true}
        }
        if(st%3==0.toLong()&&mp[st/3]!=null)
        {
            if(mp[st/3]!!){
                st/=3
                mp[st]=false
                newarray.add(st)
                chk=true}
        }
        if(!chk)break
    }
    for(i in newarray) print(""+i+" ")
}