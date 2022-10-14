fun main()
{
    readLine()!!
    var a=readLine()!!
    var mx=0
    var ans=""
    for(i in 0..a.length-2)
    {
        var tmp="";tmp+=a[i];tmp+=a[i+1];var cnt=0
        for(j in i..a.length-2)
        {
            var chk="";chk+=a[j];chk+=a[j+1]
            if(chk.equals(tmp))cnt++

        }
       if(mx<cnt){ans=tmp;mx=cnt}

    }
    print(ans)
}