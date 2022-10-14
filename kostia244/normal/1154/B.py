def li():
  return list(map(int, input().split(" ")))
input()
#
a = sorted(list(set(li())));
if len(a) > 3:
  print(-1)
elif len(a) == 3:
  if((a[0]+a[2])%2 == 0 and (a[0]+a[2])//2 == a[1]):
    print(abs(a[1]-a[0]))
  else:
    print(-1)
elif len(a) == 2:
  if((a[1]-a[0])%2 == 0):
    print(abs((a[1]-a[0])//2))
  else:
    print(abs(a[1]-a[0]))
elif len(a) == 1:
  print(0)