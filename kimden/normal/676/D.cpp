#include <bits/stdc++.h>
using namespace std;

struct Block {
   bool isUp,isDown,isLeft,isRight;
   Block(char c='*');
   void load(char c='*');
   void rotate();
};

Block::Block(char c){
   load(c);
}

void Block::rotate(){
   bool b = isUp;
   isUp = isLeft;
   isLeft = isDown;
   isDown = isRight;
   isRight = b;
   return;
}

void Block::load(char c){
   isUp = isDown = isLeft = isRight = false;
   switch(c){
   case '+':
      isUp = isDown = isLeft = isRight = true;
      break;
   case '-':
      isLeft = isRight = true;
      break;
   case '|':
      isUp = isDown = true;
      break;
   case '^':
      isUp = true;
      break;
   case 'v':
      isDown = true;
      break;
   case '<':
      isLeft = true;
      break;
   case '>':
      isRight = true;
      break;
   case 'L':
      isUp = isDown = isRight = true;
      break;
   case 'R':
      isUp = isDown = isLeft = true;
      break;
   case 'U':
      isDown = isLeft = isRight = true;
      break;
   case 'D':
      isUp = isLeft = isRight = true;
      break;
   }
}

int main()
{
   int n,m,xt,yt,xm,ym,mm;
   cin >> n >> m;
   vector<vector<int>> g;
   for(int i=0;i<m*n*4;i++){
      g.push_back(vector<int>());
   }
   Block **b;
   char c;
   b = new Block*[n];
   for(int i=0;i<n;i++){
      b[i] = new Block[m];
      for(int j=0;j<m;j++){
         c = '\n';
         while(c=='\n')
            cin >> c;
         b[i][j].load(c);
      }
   }
   for(int k=0;k<4;k++){
      for(int i=1;i<n;i++){
         for(int j=0;j<m;j++){
            if(b[i-1][j].isDown && b[i][j].isUp){
               g[j+(i-1)*m+k*m*n].push_back(j+i*m+k*m*n);
               g[j+i*m+k*m*n].push_back(j+(i-1)*m+k*m*n);
            }
         }
      }
      for(int i=0;i<n;i++){
         for(int j=1;j<m;j++){
            if(b[i][j-1].isRight && b[i][j].isLeft){
               g[(j-1)+i*m+k*m*n].push_back(j+i*m+k*m*n);
               g[j+i*m+k*m*n].push_back((j-1)+i*m+k*m*n);
            }
         }
      }
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            g[j+i*m+k*m*n].push_back(j+i*m+((k+1)%4)*m*n);
            b[i][j].rotate();
         }
      }
   }
   cin >> xt >> yt >> xm >> ym;
   xm--;
   ym--;
   xt--;
   yt--;
   mm = m*xm+ym; // what's with the task? x is for rows, y is for cols?
   int cur = m*xt+yt;
   int step;
   deque<pair<int,int>> q;
   vector<char> used;
   for(int i=0;i<m*n*4;i++){
      used.push_back(0);
   }
   if(cur%(m*n)==mm){
      cout << 0;
      return 0;
   }
   q.push_back(make_pair(cur,0));
   while(!q.empty()){
      cur = q.front().first;
      step = q.front().second;
      q.pop_front();
      for(auto v: g[cur]){
         if(!used[v]){
            if(v%(m*n)==mm){
               cout << step+1;
               return 0;
            }
            used[v] = 1;
            q.push_back(make_pair(v,step+1));
         }
      }
   }
   cout << -1;
   return 0;
}