expr = '1*' + input() + '*1'
muls = [i for i in range(len(expr)) if expr[i] == '*']
result = 0
for i in muls:
    for j in muls:
        if j > i:
            s = expr[:i + 1] + '(' + expr[i + 1: j] + ')' + expr[j:]
            result = max(result, eval(s))
print(result)