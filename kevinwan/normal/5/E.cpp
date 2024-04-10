#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e6+10;
int cnt[mn];
bool ins[mn];
int a[mn];
int as;
vector<int>nums;
map<int,int>comp;
stack<int>s;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i),a[i+n]=a[i],nums.push_back(a[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=0;i<2*n;i++)a[i]=comp[a[i]];
    int mo=0,mo2=0;
    for(int i=0;i<n;i++)if(a[i]==nums.size()-1)mo++;
    for(int i=0;i<n;i++)if(a[i]+1==nums.size()-1)mo2++;
    ll ans=0;
    int lar=-1;
    for(int i=0;i<2*n;i++){
        if(i>=n&&ins[i-n]){
            ins[i-n]=0;
            cnt[a[i-n]]--;
            as--;
        }
        if(i>=n) {
            if (a[i] < lar)continue;
            else lar = a[i];
        }
        while(s.size()&&a[s.top()]<a[i]){
            if(s.top()<=i-n)goto vesh;
            ans++;
            ins[s.top()]=0;
            cnt[a[s.top()]]--;
            s.pop();
            as--;
        }
        if(s.size()&&s.top()<=i-n)goto vesh;
        if(s.size())ans+=min(as,cnt[a[i]]+1);
        if(i<n) {
            s.push(i);
            cnt[a[i]]++;
            ins[i] = 1;
            as++;
        }
    }
    vesh:
    if(mo>=2)ans-=1LL*mo*(mo-1)/2;
    else ans-=mo2;
    printf("%lld",ans);
}