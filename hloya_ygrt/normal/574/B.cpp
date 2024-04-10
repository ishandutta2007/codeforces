#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int m;
    int a,b;
    int kolvo=1e9;
    int l,k,f,s;
    int z[4001];
    vector <int> i[4001];
    cin>>n>>m;
    for (l=0;l<=n;l++) z[l]=0;
    for (;m>0;m--)
    {
        cin>>a>>b;
        z[a]++;
        z[b]++;
        i[a].push_back(b);
        i[b].push_back(a);
    }

    for (m=1;m<=n;m++)
        sort(i[m].begin(),i[m].end());

    for (m=1;m<=n;m++){
        k=i[m].size();
        for (l=0;l<k;l++)
        {
            f=0;
            s=0;

            while (f<i[m].size()&&s<i[i[m][l]].size())
            {
                if (i[m][f]<i[i[m][l]][s]) {f++;
                continue;
                }

                if (i[m][f]>i[i[m][l]][s]) {s++;
                continue;
                }

                if (i[m][f]==i[i[m][l]][s]) {

                        kolvo=min(kolvo,z[m]+z[i[m][l]]+z[i[m][f]]-6);

                        f++;

                        }

            }
        }
    }

    if (kolvo==1e9) cout<<-1; else cout<<kolvo;
    return 0;
}