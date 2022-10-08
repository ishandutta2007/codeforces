#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>

using namespace std;

const int INF = 1000007, LIMIT=4000000;
char buf[20];
int tab[20][20], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1}, tmp[LIMIT][9], roz[LIMIT], wyn = INF, dl = 0, kolejka[LIMIT], pocz=0, kon=0;
set <vector <int> > S;
vector <int> V;

void fun()
{
    kolejka[pocz++] = 0;
    int licz = 0;
    for(int j=0; j<dl; j++)
        V.push_back(tmp[0][j]);
    S.insert(V);
    V.clear();
    while(pocz!=kon)
    {
        int stan = kolejka[kon++], odl = roz[stan];
        int glowax=tmp[stan][0]/30, gloway=tmp[stan][0]%30; 
        for(int i=0; i<4; i++)
        {
            int tx = glowax+dx[i], ty = gloway+dy[i];
            if(tab[tx][ty]==-2)
            {
                wyn = odl+1;
                return;
            }
            if(tab[tx][ty]!=-1)
            {
                bool czy = 1;
                for(int j=0; j<dl-1; j++)
                    if(tmp[stan][j]/30 == tx && tmp[stan][j]%30 == ty)
                        czy = 0;
                if(czy)
                {
                    ++licz;
                    roz[licz] = odl+1;
                    for(int j=1; j<dl; j++)
                        tmp[licz][j] = tmp[stan][j-1];
                    tmp[licz][0] = tx*30+ty;
                    for(int j=0; j<dl; j++)
                        V.push_back(tmp[licz][j]);
                    if(S.count(V)==0)
                    {
                        kolejka[pocz++]=licz;
                        S.insert(V);
                    }
                    V.clear();
                }
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%s", buf);
        for(int j=0; j<m; j++)
        {
            if(buf[j]=='#')
                tab[i][j+1]=-1;
            if(buf[j]>'0' && buf[j]<='9')
            {
                dl = max(dl, buf[j]-'0');
                tmp[0][buf[j]-'1'] = i*30+j+1;
            }
            if(buf[j]=='@')
                tab[i][j+1] = -2;
        }
    }
    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=m+1; j++)
            if(i==0 || j==0 || i==n+1 || j==m+1)
                tab[i][j] = -1;
    fun();
    printf("%d", wyn==INF ? -1 : wyn);
    return 0;
}