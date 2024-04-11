def main():
    import sys
    
    a, b, c = sys.stdin.read().split()
    la = [0] * 26
    lb = [0] * 26
    lc = [0] * 26
    for i in a: la[ord(i) - ord('a')] += 1
    for i in b: lb[ord(i) - ord('a')] += 1
    for i in c: lc[ord(i) - ord('a')] += 1
    
    result = 0
    res_b = res_c = 0
    for i in range(10 ** 5):
        t = float("inf")
        for j in range(26):
            if la[j] < lb[j] * i:
                t = -1
                break
            if lc[j]:
                t = min(t, (la[j] - lb[j] * i) // lc[j])
        if t < 0:
            break
        if i + t > result:
            res_b, res_c = i, t
            result = i + t
    
    result = b * res_b + c * res_c
    result += ''.join(chr(i + ord('a')) * (la[i] - lb[i] * res_b - lc[i] * res_c) for i in range(26))
    
    sys.stdout.write(''.join(result))
    
    
main()