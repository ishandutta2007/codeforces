samogloski = "aeiouyAEIOUY"

def foo(x):
  X = []
  for litera in x:
    if litera not in samogloski:
      X.append(litera.lower())
  res = ".".join(X)
  if len(X)>0:
    res = '.'+res
  return res

n = 1
for i in range(n):
  print(foo(input()))