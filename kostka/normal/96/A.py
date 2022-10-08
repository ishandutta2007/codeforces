a = input()

def check(i):
  for j in range(i, i+7):
    if a[i] != a[j]:
      return False
  return True

def bettercheck():
  for i in range(len(a)-6):
    if check(i):
      return True
  return False
    
if bettercheck():
  print("YES")
else:
  print("NO")