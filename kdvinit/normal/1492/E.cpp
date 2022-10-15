/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }

    int mxd=0, ind;
    for(int i=2;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!=a[1][j]) cnt++;
        }
        if(cnt>mxd)
        {
            mxd=cnt;
            ind=i;
        }
    }

    if(mxd<=2)
    {
        cout<<"Yes"<<endl;
        for(int j=1;j<=m;j++) cout<<a[1][j]<<" ";
        cout<<endl;
        return;
    }

    if(mxd>4)
    {
        cout<<"No"<<endl;
        return;
    }

    //if(n==25 && m==10000 && a[1][1]==650677392) cout<<mxd<<" "<<ind<<endl;

    if(mxd==4)
    {
        int diff[4];
        int cnt=0;
        for(int j=1;j<=m;j++)
        {
            if(a[ind][j]!=a[1][j])
            {
                diff[cnt]=j;
                cnt++;
            }
        }

        int w=diff[0], x=diff[1], y=diff[2], z=diff[3];

        int already[n+1]={0};

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]!=a[1][j])
                {
                    if(j==w || j==x || j==y || j==z) continue;
                    tmp++;
                }

            }
            already[i]=tmp;
        }

        int pos;

        w=diff[0], x=diff[1], y=diff[2], z=diff[3];
        pos=1;

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][w]!=a[1][w]) tmp++;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            if(a[i][z]!=a[ind][z]) tmp++;

            tmp+=already[i];

            if(tmp>2) { pos=0; break; }
        }

        if(pos==1)
        {
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==w) { cout<<a[1][w]<<" "; continue; }
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<a[ind][z]<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }

        w=diff[0], x=diff[2], y=diff[1], z=diff[3];
        pos=1;

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][w]!=a[1][w]) tmp++;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            if(a[i][z]!=a[ind][z]) tmp++;

            tmp+=already[i];

            if(tmp>2) { pos=0; break; }
        }

        if(pos==1)
        {
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==w) { cout<<a[1][w]<<" "; continue; }
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<a[ind][z]<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }

        w=diff[0], x=diff[3], y=diff[2], z=diff[1];
        pos=1;

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][w]!=a[1][w]) tmp++;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            if(a[i][z]!=a[ind][z]) tmp++;

            tmp+=already[i];

            if(tmp>2) { pos=0; break; }
        }

        if(pos==1)
        {
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==w) { cout<<a[1][w]<<" "; continue; }
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<a[ind][z]<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }

        w=diff[1], x=diff[2], y=diff[0], z=diff[3];
        pos=1;

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][w]!=a[1][w]) tmp++;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            if(a[i][z]!=a[ind][z]) tmp++;

            tmp+=already[i];

            if(tmp>2) { pos=0; break; }
        }

        if(pos==1)
        {
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==w) { cout<<a[1][w]<<" "; continue; }
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<a[ind][z]<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }

        w=diff[1], x=diff[3], y=diff[0], z=diff[2];
        pos=1;

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][w]!=a[1][w]) tmp++;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            if(a[i][z]!=a[ind][z]) tmp++;

            tmp+=already[i];

            if(tmp>2) { pos=0; break; }
        }

        if(pos==1)
        {
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==w) { cout<<a[1][w]<<" "; continue; }
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<a[ind][z]<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }

        w=diff[2], x=diff[3], y=diff[0], z=diff[1];
        pos=1;

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][w]!=a[1][w]) tmp++;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            if(a[i][z]!=a[ind][z]) tmp++;

            tmp+=already[i];

            if(tmp>2) { pos=0; break; }
        }

        if(pos==1)
        {
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==w) { cout<<a[1][w]<<" "; continue; }
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<a[ind][z]<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }

        cout<<"No"<<endl;
        return;
    }
    else
    {
        int diff[3];
        int cnt=0;
        for(int j=1;j<=m;j++)
        {
            if(a[ind][j]!=a[1][j])
            {
                diff[cnt]=j;
                cnt++;
            }
        }

        int already[n+1]={0};

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]!=a[1][j])
                {
                    if(j==diff[0] || j==diff[1] || j==diff[2]) continue;
                    tmp++;
                }
            }
            already[i]=tmp;
        }

        int x=diff[0],y=diff[1],z=diff[2];

        //Checking x-1,y-ind,z-?
        int fix=0;
        int pos=1;
        int xtra=a[1][z];

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            tmp+=already[i];
            if(tmp<2) continue;
            if(tmp>2) { pos=0; break; }
            if(fix==1)
            {
                if(a[i][z]==xtra) continue;
                pos=0;
                break;
            }
            fix=1;
            xtra=a[i][z];
        }

        if(pos==1)
        {
            //if(n==25 && m==10000 && a[1][1]==650677392) cout<<"012"<<endl;
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<xtra<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }


        x=diff[0],y=diff[2],z=diff[1];

        //Checking x-1,y-ind,z-?
        fix=0;
        pos=1;
        xtra=a[1][z];

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            tmp+=already[i];
            if(tmp<2) continue;
            if(tmp>2) { pos=0; break; }
            if(fix==1)
            {
                if(a[i][z]==xtra) continue;
                pos=0;
                break;
            }
            fix=1;
            xtra=a[i][z];
        }

        if(pos==1)
        {
            //if(n==25 && m==10000 && a[1][1]==650677392) cout<<"021"<<endl;
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<xtra<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }




        x=diff[1],y=diff[0],z=diff[2];

        //Checking x-1,y-ind,z-?
        fix=0;
        pos=1;
        xtra=a[1][z];

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            tmp+=already[i];
            if(tmp<2) continue;
            if(tmp>2) { pos=0; break; }
            if(fix==1)
            {
                if(a[i][z]==xtra) continue;
                pos=0;
                break;
            }
            fix=1;
            xtra=a[i][z];
        }

        if(pos==1)
        {
            //if(n==25 && m==10000 && a[1][1]==650677392) cout<<"102"<<endl;
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<xtra<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }




        x=diff[1],y=diff[2],z=diff[0];

        //Checking x-1,y-ind,z-?
        fix=0;
        pos=1;
        xtra=a[1][z];

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            tmp+=already[i];
            if(tmp<2) continue;
            if(tmp>2) { pos=0; break; }
            if(fix==1)
            {
                if(a[i][z]==xtra) continue;
                pos=0;
                break;
            }
            fix=1;
            xtra=a[i][z];
        }

        if(pos==1)
        {
            //if(n==25 && m==10000 && a[1][1]==650677392) cout<<"120"<<endl;
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<xtra<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }




        x=diff[2],y=diff[0],z=diff[1];

        //Checking x-1,y-ind,z-?
        fix=0;
        pos=1;
        xtra=a[1][z];

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            tmp+=already[i];
            if(tmp<2) continue;
            if(tmp>2) { pos=0; break; }
            if(fix==1)
            {
                if(a[i][z]==xtra) continue;
                pos=0;
                break;
            }
            fix=1;
            xtra=a[i][z];
        }

        if(pos==1)
        {
            //if(n==25 && m==10000 && a[1][1]==650677392) cout<<"201"<<endl;
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<xtra<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }





        x=diff[2],y=diff[1],z=diff[0];

        //Checking x-1,y-ind,z-?
        fix=0;
        pos=1;
        xtra=a[1][z];

        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            if(a[i][x]!=a[1][x]) tmp++;
            if(a[i][y]!=a[ind][y]) tmp++;
            tmp+=already[i];
            if(tmp<2) continue;
            if(tmp>2) { pos=0; break; }
            if(fix==1)
            {
                if(a[i][z]==xtra) continue;
                pos=0;
                break;
            }
            fix=1;
            xtra=a[i][z];
        }

        if(pos==1)
        {
            //if(n==25 && m==10000 && a[1][1]==650677392) cout<<"210"<<endl;
            cout<<"Yes"<<endl;
            for(int j=1;j<=m;j++)
            {
                if(j==x) { cout<<a[1][x]<<" "; continue; }
                if(j==y) { cout<<a[ind][y]<<" "; continue; }
                if(j==z) { cout<<xtra<<" "; continue; }
                cout<<a[1][j]<<" ";
            }
            cout<<endl;
            return;
        }

        cout<<"No"<<endl;
        return;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}