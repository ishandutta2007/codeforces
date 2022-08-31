/*
I tried to make you happy
You know I tried so hard to be
What you hoped that I would be
I gave you what wanted
God couldn't give you what you need
You wanted more from me
Than I could ever be
You wanted heart and soul
But you didn't know, baby

Wild, wild is the wind
That takes me away from you
Cold is the night without your love
To see me through
Wild, wild is the wind
That blows through my heart

Wild is the wind,
Wild is the wind
You got to understand, baby
Wild is the wind

You need someone to hold you
Somebody to be there night and day
Someone to kiss your fears away
I just went on pretending
Too weak, too proud, too tough to say
I couldn't be the one
To make your dreams come true
That's why I had to run
Though I needed you, baby

Wild, wild is the wind
That takes me away from you
Cold is the night without your love
To see me through, baby
Wild, wild is the wind
That blows through my heart tonight
That tears us apart

Wild is the wind,
Wild is the wind
You got to understand, baby
Wild is the wind

Maybe a better man
Would live and die for you
Baby, a better man would
Never say goodbye to you

Wild, wild is the wind
That takes me away from you
Cold is the night without your love
To see me through, baby
Wild, wild is the wind
That blows through my heart tonight
That tears us apart

Wild is the wind,
Wild is the wind
You got to understand, baby
Wild is the wind
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int tests;
int n, m;
int deg[N];
int ar[300][300], Real[300][300];
int used[300];
vector<int> comp;

void dfs(int v)
{
	used[v] = 1;
	comp.push_back(v);
	for (int i = 1; i <= n; i++)
	{
		if (ar[v][i] == 0)
			continue;
		if (used[i])
			continue;
		dfs(i);
	}
}

vector<pair<int, int> > Euler;

int M[500][500];

vector<int> O;

void solver(int v)
{
//	cout<<"%%%%%"<<v<<endl;
	used[v] = 1;

	int flag=0;

	for (int i = 1; i <= n; i++)
	{
		if (ar[v][i])
		{
			ar[v][i]--;
			ar[i][v]--;
			solver(i);
			//cout<<"back to "<<v<<endl;
//			Euler.push_back(make_pair(i,v));
		}
	}

	O.push_back(v);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> n >> m;
		O.clear();
		for (int i = 1; i <= n; i++)
			deg[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				ar[i][j] = 0;
				Real[i][j] = 0;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			cin >> a >> b;
			deg[a]++;
			deg[b]++;
			ar[a][b] = ar[b][a] = 1;
			Real[a][b] = Real[b][a] = 1;
		}

		vector<int> bad;

		for (int i = 1; i <= n; i++)
		{
			used[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			if (used[i])
				continue;
			comp.clear();
			dfs(i);
			for (int j = 0; j < comp.size(); j++)
			{
				int v = comp[j];
				if (deg[v] % 2)
					bad.push_back(v);
			}
		}

		//cout<<bad.size()<<"%"<<endl;
		for (int i = 0; i + 1 < bad.size(); i += 2)
		{
			int a, b;
			a = bad[i];
			b = bad[i + 1];
			//cout<<a<<"%%%"<<b<<endl;
			ar[a][b]++;
			ar[b][a]++;
			deg[a]++;
			deg[b]++;
		}

		cout << n - bad.size() << endl;

//		cout << "%" << endl;

		Euler.clear();

		for (int i = 1; i <= n; i++)
		{
			used[i] = 0;
		}
		int s=0;
		for (int i=1;i<=n;i++)
		{
			int here=0;
			for (int j=1;j<=n;j++)
			{
				here+=ar[i][j];
				s+=ar[i][j];
			}
			//cout<<here<<endl;
		}

		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				M[i][j]=ar[i][j];
//				cout<<ar[i][j]<<" ";
			}
//			cout<<endl;
		}

		for (int ii = 1; ii <= n; ii++)
		{
			if (used[ii])
				continue;
			//cout<<ii<<"%%%"<<endl;
			O.clear();
			solver(ii);
		/*	for (int i=0;i<O.size();i++)
			{
				cout<<O[i]<<" ";
			}
			cout<<endl;
*/
			for (int i = 0; i+1<O.size(); i++)
			{
				int v1 = O[i];
				int v2 = O[i+1];
	//			cout<<M[v1][v2]<<endl;

				if (Real[v1][v2])
				{
					cout << v1 << " " << v2 << endl;
					Real[v1][v2]=0;
					Real[v2][v1]=0;
				}
			}
		}

		/*cout<<"@"<<s<<endl;

		//cout<<"@@"<<O.size()<<endl;

		for (int i=0;i<O.size();i++)
		{
			cout<<O[i]<<"   ";
		}
		cout<<endl;
*/

	}


	cin.get(); cin.get();
	return 0;
}