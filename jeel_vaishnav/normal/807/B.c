#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
    {
int p,x,y,count=0,check=0;
    scanf("%d%d%d",&p,&x,&y);
    if(x>y)
        {
        int temp=x;
        while(temp>=y)
            {
            int i=(temp/50)%475,flag=0;
        for(int x=0;x<25;x++)
            {
           i=(i*96+42)%475;
            if(26+i==p)
                flag=1;
        }
        if(flag==1)
            {
            check=1;
            break;
        }
        else
            {
            temp-=50;
        }
        }
    }
    if(x<y)
        {
        if(y-x%50==0)
            {
            count+=(y-x)/50;
            x=y;
        }
        else
            {
            count+=(y-x)/50+1;
            x=x+50*count;
        }
    }
    if(check==0)
        {
    while(1)
        {
        int i=(x/50)%475,flag=0;
        for(int x=0;x<25;x++)
            {
           i=(i*96+42)%475;
            if(26+i==p)
                flag=1;
        }
        if(flag==1)
            break;
        else
            {
            x+=50;
            count+=1;
        }
    }
    }
        printf("%d",(count+1)/2);
    return 0;
}