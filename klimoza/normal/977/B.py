n = int(input())
s = input()
dict = dict()
maxs = s[0] + s[1]
maxi = 1
dict[s[0] + s[1]] = 1
for i in range(1, n - 1):
    if(dict.get(s[i] + s[i + 1], -1) == -1):
        dict[s[i] + s[i + 1]] = 1
    else:
        dict[s[i] + s[i + 1]] += 1
    if dict[s[i] + s[i + 1]] > maxi:
        maxi = dict[s[i] + s[i + 1]]
        maxs = s[i] + s[i + 1]
print(maxs)