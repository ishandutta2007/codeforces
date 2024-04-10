#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define fi first
#define se second
#define distance dis

const int sizee=23;

int number [sizee] [sizee];
vector <int> possible_xors [2] [sizee] [sizee];
int distance [2] [sizee] [sizee];
int visited [2] [sizee] [sizee];
int n,m,k;
int ans=0;


void top_left_corner ()
{
    possible_xors[0][1][1].push_back(number[1][1]);

    queue<pair<int,int>> Q;

    Q.push(mp(1,1));

    while (!Q.empty())
    {
        auto current=Q.front();
        Q.pop();

        if (distance[0][current.fi][current.se]!=m-1 && number[current.fi][current.se]!=-1 && visited[0][current.fi][current.se]==0)
        {
            visited[0][current.fi][current.se]=-1;

            distance[0][current.fi+1][current.se]=distance[0][current.fi][current.se+1]=distance[0][current.fi][current.se]+1;

            for (int i=0; i<possible_xors[0][current.fi][current.se].size(); i++)
            {
                // possible_xors[0][current.fi][current.se][i]=possible_xors[0][current.fi][current.se][i]^number[current.fi][current.se];

                possible_xors[0][current.fi+1][current.se].push_back(possible_xors[0][current.fi][current.se][i]^number[current.fi+1][current.se]);
                possible_xors[0][current.fi][current.se+1].push_back(possible_xors[0][current.fi][current.se][i]^number[current.fi][current.se+1]);

            }
            Q.push(mp(current.fi,current.se+1));
            Q.push(mp(current.fi+1,current.se));
        }
    }
}

void bottom_right_corner ()
{
    possible_xors[1][m][n].push_back(0);

    queue<pair<int,int>> Q;

    Q.push(mp(m,n));

    while (!Q.empty())
    {
        auto current=Q.front();
        Q.pop();

        if (distance[1][current.fi][current.se]!=n-1 && number[current.fi][current.se]!=-1 && visited[1][current.fi][current.se]==0)
        {

            visited[1][current.fi][current.se]=-1;

            distance[1][current.fi-1][current.se]=distance[1][current.fi][current.se-1]=distance[1][current.fi][current.se]+1;

            for (int i=0; i<possible_xors[1][current.fi][current.se].size(); i++)
            {
                // possible_xors[1][current.fi][current.se][i]=possible_xors[1][current.fi][current.se][i]^number[current.fi][current.se];

                possible_xors[1][current.fi-1][current.se].push_back(possible_xors[1][current.fi][current.se][i]^number[current.fi][current.se]);
                possible_xors[1][current.fi][current.se-1].push_back(possible_xors[1][current.fi][current.se][i]^number[current.fi][current.se]);
            }
            Q.push(mp(current.fi,current.se-1));
            Q.push(mp(current.fi-1,current.se));

        }
    }
}

void loading ()
{
    cin>>n>>m>>k;

    for (int i=0; i<sizee; i++)
        for (int j=0; j<sizee; j++)
            number[i][j]=-1;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>number[j][i];
}

void action ()
{

    for (int i=0; i<sizee; i++)
        for (int j=0; j<sizee; j++)
            if(possible_xors[0][i][j].size()>0ll && possible_xors[1][i][j].size()>0ll)
            {

                sort(possible_xors[0][i][j].begin(),possible_xors[0][i][j].end());

                for (int h=0; h<possible_xors[1][i][j].size(); h++)
                {
                    auto xx=equal_range(possible_xors[0][i][j].begin(),possible_xors[0][i][j].end(), possible_xors[1][i][j][h]^k);
                    ans+=xx.se-xx.fi;

                }
            }
    cout <<ans<<endl;
}


main()
{
    loading();
    top_left_corner();
    bottom_right_corner();
    action();

/*
cout <<n<<" "<<m<<" "<<k<<endl;
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
            cout <<number[j][i]<<" ";
        cout<<endl;
    }
    cout <<endl;

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
            cout <<possible_xors[0][j][i].size()<<" ";
        cout<<endl;
    }
    cout <<endl;
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
            cout <<possible_xors[1][j][i].size()<<" ";
        cout<<endl;
    }

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {

            int x=possible_xors[0][j][i].size();
            if(x>0)
            {
                cout <<i<<" "<<j<<": ";
            for (int w=0; w<x; w++)
                cout <<possible_xors[0][j][i][w]<<" ";
            cout <<endl;
            }
        }
    }

      for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {

            int x=possible_xors[1][j][i].size();
            if(x>0)
            {
                cout <<i<<" "<<j<<": ";
            for (int w=0; w<x; w++)
                cout <<possible_xors[1][j][i][w]<<" ";
            cout <<endl;
            }
        }
    }
    */
}