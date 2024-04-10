    #include<cstdio>
    using namespace std;
    int t,Nowx,Nowy;
    char s[15];
    void check(int x,int y)
    {
        printf("%d %d\n",x,y);
        Nowx=x; Nowy=y;
        fflush(stdout);
        s[4]='\0';
        scanf("%s",s+1);
    }
    int main()
    {
        scanf("%d",&t);
        while(t--)
        {
            Nowx=1;
            Nowy=1;
            check(1,1);
            bool Checked=false;
            bool Sweeping=true;
            while(s[4]!='e')
            {
                if(!Sweeping) 
                {
                    Checked=false;
                    Sweeping=true;
                    if(Nowy!=1) check(Nowx,1);
                    else check(Nowx,2);
                    continue;
                }
                if(Checked && Nowy==1)
                {
                    Checked=false;
                    check(Nowx+1,1);
                    continue;
                }
                if(s[1]=='U')
                {
                    Sweeping=false;
                    continue;
                }
                if(s[1]=='D')
                {
                    check(Nowx+1,Nowy);
                    Sweeping=false;
                    continue;
                }
                if(Nowy==8)
                {
                    Checked=true;
                    check(Nowx,1);
                }
                else
                {
                    check(Nowx,Nowy+1);
                    continue;
                }
            }
        }
    }