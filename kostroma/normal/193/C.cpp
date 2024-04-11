#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main() 
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;

}

//#define int li

double EPS = 1e-9;
int INF=1<<30;

double a[7][8];

int gauss (vector<double> & ans) 
{
	int n = 7;
	int m = 7;
 
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) 
        {
		int sel = row;
		for (int i=row; i<n; ++i)
			if ( fabs (a[i][col]) > fabs (a[sel][col]))
				sel = i;
		if (fabs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) 
                        {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}
 
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) 
        {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if ( fabs (sum - a[i][m]) > EPS)
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}

string anss[4];

string qq[7];

double aaa[7];

void solve()
{  
    
    for (int i=0; i<6; i++)
        cin>>aaa[i];
    
    qq[0]="abbb";
    qq[1]="babb";
    qq[2]="bbab";
    qq[3]="bbba";
    qq[4]="aabb";
    qq[5]="abab";
    qq[6]="abba";
    
    
    for (int l=0; l<=400000; l++)
    {
        a[0][0]=a[0][1]=a[0][5]=a[0][6]=1.0; a[0][2]=a[0][3]=a[0][3]=0.0;
        a[1][0]=a[1][2]=a[1][4]=a[1][6]=1.0; a[1][1]=a[1][3]=a[1][5]=0.0;
        a[2][0]=a[2][3]=a[2][4]=a[2][5]=1.0; a[2][1]=a[2][2]=a[2][6]=0.0;
        a[3][1]=a[3][2]=a[3][4]=a[3][5]=1.0; a[3][0]=a[3][3]=a[3][6]=0.0;
        a[4][1]=a[4][3]=a[4][4]=a[4][6]=1.0; a[4][0]=a[4][2]=a[4][5]=0.0;
        a[5][2]=a[5][3]=a[5][5]=a[5][6]=1.0; a[5][0]=a[5][1]=a[5][4]=0.0;
        
        a[6][0]=a[6][1]=a[6][2]=a[6][3]=a[6][4]=a[6][5]=a[6][6]=1.0;
        
        a[6][7]=(double)l;
        
        for (int i=0; i<6; i++)
            a[i][7]=aaa[i];
        
        
        vector <double> ans;
        int now=gauss(ans);
        
        if (now==0)
            continue;
        
        
        bool f=true;
        vector <int> answer;
        for (int i=0; i<ans.size(); i++)
        {
            if (ans[i]<-EPS)
            {
                f=false;
                break;
            }
            ans[i]+=EPS;
            int cur=(int)ans[i];
            answer.pb(cur);
            double nn=(double)cur;
            if ( fabs (nn-ans[i]) > 1e-7 )
            {
                f=false;
                break;
            }
        }
        if (!f)
            continue;
        
        /*for (int i=0; i<7; i++)
            cout<<answer[i]<<' ';
        cout<<endl;*/
        
        cout<<l<<endl;
        for (int i=0; i<7; i++)
            for (int j=0; j<answer[i]; j++)
                for (int w=0; w<4; w++)
                    anss[w].pb( qq[i][w] );
            for (int w=0; w<4; w++)
                cout<<anss[w]<<endl;
            return;
    }
    
    cout<<"-1";
    
}