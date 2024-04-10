#include <bits/stdc++.h>

#define INF 2 * 1e9
#define C   31ULL
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef unsigned long long int ull;
typedef long long int ll;
 
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    for(auto elem: vec)
        cout << elem << " ";
 
    return os;
}
 
template<typename T>
ostream& operator<<(ostream& os, const set<T>& a)
{
	for(auto elem: a)
		cout << a << " ";
 
    return os;
}
 
template<typename T>
T max3(T a, T b, T c)
{
    return max(max(a, b), c);
}
 
template<typename T>
T min3(T a, T b, T c)
{
    return min(min(a, b), c);
}
 
template<typename T>
void read_vector(vector<T>& vec, int size)
{
    vec.resize(size);
 
    for(int i = 0; i < size; ++i)
        cin >> vec[i];
}

const int K = 1000;

struct Query
{
	int idx, l, r;
    ll answer = -1;

	bool operator<(const Query& other)
	{
		if(answer == -1)
		{
			if(l / K != other.l / K)
				return l < other.l;

			return r < other.r;
		}
		else
		{
			return idx < other.idx;
		}
	}
};

vector<ll> a;

int L, R;
ll freq[1000010];
ll val;

void initLR(int s)
{
	L = R = s;

	for(int i = 0; i < 1000010; ++i)
		freq[i] = 0;

	++freq[a[s]];
	val = a[s];
}

void moveL()
{
	{
		ll v = a[L] * freq[a[L]] * freq[a[L]];

		val -= v;
	}

	--freq[a[L]];

	{
		ll v = a[L] * freq[a[L]] * freq[a[L]];

		val += v;
	}

	++L;

	//cout << "moveL: ";
	//cout << "L,R=" << L << "," << R << endl;
	//cout << "val=" << val << endl;
}

void decL()
{
	{
		ll v = a[L - 1] * freq[a[L - 1]] * freq[a[L - 1]];

		val -= v;
	}

	++freq[a[L - 1]];

	{
		ll v = a[L - 1] * freq[a[L - 1]] * freq[a[L - 1]];

		val += v;
	}

	--L;

	//cout << "decL: ";
	//cout << "L,R=" << L << "," << R << endl;
	//cout << "val=" << val << endl;
}

void moveR()
{
	{
		ll v = a[R + 1] * freq[a[R + 1]] * freq[a[R + 1]];

		val -= v;
	}

	++freq[a[R + 1]];

	{
		ll v = a[R + 1] * freq[a[R + 1]] * freq[a[R + 1]];

		val += v;
	}

	++R;

	//cout << "moveR: ";
	//cout << "L,R=" << L << "," << R << endl;
	//cout << "val=" << val << endl;
}

int main(int argc, char** argv)
{
	int n, t;
	vector<Query> q;
	FAST_IO

	cin >> n >> t;
	read_vector(a, n);

	for(int i = 0; i < t; ++i)
	{
		Query nq;

		nq.idx = i;
		cin >> nq.l >> nq.r;

		--nq.l, --nq.r;

		q.push_back(nq);
	}

	sort(q.begin(), q.end());

	int i = 0;

	for(int b = 0; b <= (n - 1) / K; ++b)
	{
		initLR(K * b);

		while(i < t && q[i].l / K == b)
		{
			while(R < q[i].r)
				moveR();

			while(q[i].l > L)
				moveL();

			while(q[i].l < L)
				decL();

			q[i].answer = val;

			++i;
		}
	}

	sort(q.begin(), q.end());

	for(auto elem: q)
		cout << elem.answer << endl;

	return 0;
}