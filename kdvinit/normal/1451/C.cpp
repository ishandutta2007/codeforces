#include<iostream>
#include<cstdio>
using namespace std;

int func(int* count1, int* count2, int k){
    int countKsets = 0, i;
    for(i=(int)'a'; i<=(int)'z'; i++){
        if(countKsets <= count2[i]/k){
            count2[i] -= countKsets*k;
            countKsets = 0;
        }
        else{
            countKsets -= count2[i]/k;
            count2[i] = count2[i]%k;
        }
        if(count1[i] < count2[i])
            return 0;
        else{
            count1[i] -= count2[i];
            if(count1[i]%k != 0)
                return 0;
            else
                countKsets += count1[i]/k;
        }
    }
    return 1;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int count1[150] = {};
        int count2[150] = {};
        char c;
        
        while(getchar() != '\n');
        for(int i=0; i<n; i++){
            c = getchar();
            if((int)c <= 'z' && (int)c >= 'a') count1[c]++;
        }
        while(getchar() != '\n');
        // for(int i='a'; i<='z'; i++){
        //     cout << count1[i] << " ";
        // }
        // cout << endl;
        for(int i=0; i<n; i++){
            c = getchar();
            if((int)c <= 'z' && (int)c >= 'a') count2[c]++;
        }
        while(getchar() != '\n');
        // for(int i='a'; i<='z'; i++){
        //     cout << count2[i] << " ";
        // }
        // cout << endl;

        cout << (func(count1,count2,k) ? "Yes" : "No") << endl;
    }
    return 0;
}