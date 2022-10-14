m = dict()
for _ in range(int(input())):
  s = input()
  if(m.__contains__(s)):
    print(s + str(m[s]))
    m[s] += 1
  else:
    print("OK")
    m[s] = 1