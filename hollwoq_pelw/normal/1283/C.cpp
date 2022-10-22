#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 200010;

int n;

int v[MAXN];
int inDegree[MAXN];
int outDegree[MAXN];

vector< int > remain;

void add(int U, int V)
{
	outDegree[U]++;
	inDegree[V]++;
}

int main()
{
	scanf("%d",&n);

	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d",&v[i]);

		if( v[i] != 0 ) add( i , v[i] );
	}

	for(int i = 1 ; i <= n ; i++)
		if( inDegree[i] == 0 && outDegree[i] == 0 ) remain.push_back( i );

	for(int i = 1 ; i <= n ; i++)
	{
		if( inDegree[i] != 0 || outDegree[i] == 0 ) continue;

		int cur = i;

		while( v[cur] != 0 ) cur = v[cur];

		if( remain.size()%2 == 1 )
		{
			int V = remain.back();
			remain.pop_back();

			v[cur] = V;
			v[ V ] = i;

			add( cur , V );
			add( V , i );
		}
		else v[ cur ] = i, add( cur , i );
	}

	if( remain.size()%2 == 1 )
	{
		int sz = remain.size();

		int A = remain[sz - 1];
		int B = remain[sz - 2];
		int C = remain[sz - 3];

		v[A] = B;
		v[B] = C;
		v[C] = A;

		add( A , B );
		add( B , C );
		add( C , A );

		remain.pop_back();
		remain.pop_back();
		remain.pop_back();
	}

	while( remain.size() > 0 )
	{
		int sz = remain.size();

		int A = remain[sz - 1];
		int B = remain[sz - 2];

		v[A] = B;
		v[B] = A;

		add( A , B );
		add( B , A );

		remain.pop_back();
		remain.pop_back();
	}

	for(int i = 1 ; i <= n ; i++)
		printf("%d ",v[i]);
}