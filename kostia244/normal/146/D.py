from math import *
from fractions import *
from sys import *
def li():
  return list(map(int, input().split(" ")))
a = li()
if abs(a[2]-a[3]) > 1:
  print(-1)
  exit()
if a[2] == a[3]:
  ans = "47"*a[2]+"4"
elif a[2] > a[3]:
  ans = "47"*a[2]
else:
  ans = "74"*a[3]
f = a[0]-ans.count("4")
s = a[1]-ans.count("7")
shit =False
if s < 0 or f < 0:
  if(a[2] == a[3]):
    ans = "74"*a[2]+"7"
    shit = True
  f = a[0]-ans.count("4")
  s = a[1]-ans.count("7")
if s < 0 or f < 0:
  ans = "-1"
elif s>0 or f>0:
  s+=1
  f+=1
  if ans[:2] == "47":
    if(ans[-1] == "4"):
      ans = "4"*f + "7" + ans[2:-1] + "7"*(s-1) + "4"
    else:
      ans = "4"*f + "7" + ans[2:] + "7"*(s-1)
  else:
    if(ans[-1] == "4"):
      ans = "7" + "4"*f + ans[2:-1] + "7"*(s-1) + "4"
    else:
      ans = "7" + "4"*f + ans[2:] + "7"*(s-1)
      
print(ans)