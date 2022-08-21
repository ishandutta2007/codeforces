def solve(s, t):
    mns = list(s)
    for i in range(len(s)-2,-1,-1): mns[i] = min(mns[i], mns[i + 1])
    for i in range(len(s)):
        if s[i] != mns[i]:
            j = max(j for j, v in enumerate(s[i:], i) if v == mns[i])
            s = s[:i] + s[j] + s[i+1:j] + s[i] + s[j+1:]
            break
    return s if s < t else '---'

for cas in range(int(input())):
    print(solve(*input().split()))