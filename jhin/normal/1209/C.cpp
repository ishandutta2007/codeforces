#include <bits/stdc++.h>



using namespace std;
        int ho,mi,se,ho1,mi1;
        void fix_time()
        {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
            if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
            if(ho<0)ho+=24;if(ho>24)ho-=24;
        }
        unsigned long long my_pow(int x,int y)
        {  unsigned  long long num=1;
            for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                if(y&1)num=(num*i);
                    return num;
        }
typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

const long long INF=1e18+10;

const int inf=1e9+10,dx[]= {0,0,1,-1,1,-1,1,-1},dy[]= {1,-1,0,0,1,1,-1,-1};

ll MOD=1e9+7;

ld eps=1e-7,pi=acos(-1);







int t,m,ans[200100];

string s;


//not set
multiset <pair<char,int> > mulset;



int main()

{

ios_base::sync_with_stdio(0);



cin>>t;

while(t--)

{



    cin>>m>>s;

    for(int i=0;i<m;i++)

    {

    mulset.insert({s[i],i});

    ans[i]=0;

    }






    int stop = 1e9,last_index = -1,last_num = 0;

    bool imp = 0;



    auto it = mulset.begin();

    vector<pair<char,int> > del;

    for(int i=0;i<m;i++)

    {

    int cur_index = (*it).second;

    int cur_num = (*it).first;



        if(cur_num > stop) break;



        if(cur_index>last_index)

        {

        ans[cur_index]=1;

        last_index = cur_index;

        last_num = cur_num;

        auto tm = *it;

        del.push_back(tm);



        }

        else

        {





            stop = cur_num;

        }



        it++;

    }







    if(!del.empty())

        for(auto d:del)

            mulset.erase(d);

    it = mulset.begin();



    if(!mulset.empty())

    {

    last_index = (*it).second;

    last_num = (*it).first;



    ans[last_index] = 2;



    mulset.erase(*it);

    }





    for(auto x:mulset)

    {

        int cur_index = x.second;

        //int cur_num = x.first;



        if(cur_index<last_index)

        {

            imp = 1;

            break;

        }



        last_index = cur_index;

        ans[cur_index] = 2;



    }



    if(imp)cout<<"-";

    else

    for(int i=0;i<m;i++)

    cout<<ans[i];



    cout<<"\n";





    mulset.clear();

}



return 0;



}