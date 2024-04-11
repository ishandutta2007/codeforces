a, k = input().split()
a = [int(i) for i in a]
k = int(k)

n = 0
for i in range(len(a)):
    if n >= k: break
    max_i = i + a[i:i + 1 + k - n].index(max(a[i:i + 1 + k - n]))
    t = a.pop(max_i)
    a.insert(i, t)
    n += max_i - i
    
print(''.join(str(i) for i in a))