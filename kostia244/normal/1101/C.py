def get():
  return list(map(int, input().split(' ')))

def d():
  n = int(input())
  t = [];
  for i in range(n):
    t.append(get() + [i])
  t.sort();
  i = 0
  r = t[0][1]
  ans = ["2"]*n
  while(i < n and t[i][0] <= r):
    ans[t[i][2]] = "1"
    r = max(r, t[i][1])
    i+=1
  if "2" in ans:
    print(" ".join(ans))
  else:
    print(-1)

for i in range(int(input())):
  d()